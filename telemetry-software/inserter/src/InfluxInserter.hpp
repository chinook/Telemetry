
#ifndef INFLUX_INSERTER_HPP
#define INFLUX_INSERTER_HPP

#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string_view>

#include "curl/curl.h"
#include "InfluxDBFactory.h"
#include "InfluxDB.h"

#include "CanDecoder.hpp"

class InfluxInserter
{
public:

  // InfluxInserter manages writing to InfluxDB
  // [IN] hostname        : host to contact at port 8086 to access influxdb
  //                        ('localhost' for standalone or 'influxdb' for Docker)
  // [IN] db_name         : Name of db to write into
  // [IN] batch_size      : Size of batches to write to influx at a time
  //                        (Set to 1 for all data to be transmitted individually)
  InfluxInserter(const std::string& hostname = "localhost",
		 const std::string& db_name = "eclipsedb_1",
		 uint32_t batch_size = 50);

  // Writes a list of value pairs into the database
  // [IN] values          : Key-value pairs <name, value> to write
  // [OUT] void
  void WriteValues(const std::vector<DecodedCanValue>& values);
  
private:

  // Private init implementation
  // [OUT] void
  void InitInflux();

  
  // InfluxDB implementation
  // (from influxdb-cxx library)
  std::unique_ptr<influxdb::InfluxDB> influx_db;

  // Batch size to use for writing
  uint32_t batch_size;
  
  // InfluxDB information for writing
  std::string hostname;
  std::string db_name;
  
};


#endif // INFLUX_INSERTER_HPP
