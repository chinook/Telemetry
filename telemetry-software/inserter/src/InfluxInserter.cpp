
#include "InfluxInserter.hpp"

//
// InfluxInserter public interface
//

InfluxInserter::InfluxInserter(const std::string& hostname,
			       const std::string& db_name,
			       uint32_t batch_size)
  : hostname(hostname), db_name(db_name), batch_size(batch_size)
{
  InitInflux();
}

void InfluxInserter::WriteValues(const std::vector<DecodedCanValue>& write_values)
{
  if (!influx_db)
    throw std::runtime_error("WriteValues() : influx_db was nullptr");
  
  for (const auto& write_value : write_values)
  {
    auto& value = write_value.key_value_pair;
    try
    {
    influx_db->write(influxdb::Point{value.first}
                    .addField("value", value.second));
    // Possible to set timestamp with  .setTimestamp(time)
    // Possible to add tags with       .addTag('<key>', '<value>')
    }
    catch (std::exception e)
    {
      std::cout << "Caught exception when writing to DB" << std::endl;
      std::cout << value.first << std::endl;
      // std::cout << value.second << std::endl;
    }
  }   
}


//
// InfluxInserter private implementation functions
//

void InfluxInserter::InitInflux()
{
  // Try to access / create db
  std::string influx_command =
    "http://" + hostname + ":8086/?db=" + db_name;
  
  influx_db = influxdb::InfluxDBFactory::Get(influx_command);

  if (!influx_db)
    throw std::runtime_error("InfluxInserter() : influx_db was nullptr");

  // Set batch size of points to write at a time into InfluxDB
  if (batch_size > 1)
    influx_db->batchOf(batch_size);
}
