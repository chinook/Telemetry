ARG ALPINE_TAG=3.12

# Build stage
FROM alpine:$ALPINE_TAG AS builder

# Install libraries and create directories
RUN apk update && apk add --no-cache build-base cmake curl-dev boost && \
     mkdir -p /build/influxdb-cxx /install/influxdb-cxx /build/inserter /install/inserter

# Copy, build and install Influxdb-cxx library
COPY ./influxdb-cxx /src/influxdb-cxx

RUN cmake -S /src/influxdb-cxx -B /build/influxdb-cxx -D BUILD_SHARED_LIBS=ON && \
    cmake --build /build/influxdb-cxx --config Release && \
    cmake --install /build/influxdb-cxx --prefix /install/influxdb-cxx

# Copy, build and install custom inserter
COPY ./src /src/inserter

RUN cmake -S /src/inserter -B /build/inserter -D BUILD_SHARED_LIBS=ON -D INFLUXDB_IMPORTS=/install/influxdb-cxx/lib/cmake/InfluxDB/InfluxDBTargets.cmake && \
    cmake --build /build/inserter --config Release && \
    cmake --install /build/inserter --prefix /install/inserter


# Final image stage
FROM alpine:$ALPINE_TAG
RUN apk update && apk add --no-cache curl boost

COPY --from=builder /install/influxdb-cxx/lib /lib
COPY --from=builder /install/inserter /app

ENTRYPOINT /app/bin/eclipse-telemetry
