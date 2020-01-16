#include <avro.h>

#define SCHEMA \
"{"\
"    \"type\": \"record\","\
"    \"name\": \"engine\","\
"    \"fields\": ["\
"        {\"type\": \"double\", \"name\": \"rpm\"},"\
"        {\"type\": [\"null\",\"double\"], \"name\": \"hours\"}"\
"    ]"\
"}"

int create_record(avro_schema_t schema, avro_datum_t *result)
{
    // Create some data
    avro_datum_t record = avro_record(schema);
    avro_datum_t engine_rpm = avro_double(723.25);
    if (avro_record_set(record, "rpm", engine_rpm)
        || avro_record_set(record, "hours", avro_null())){
        fprintf(stderr, "Unable to add rpm into Avro record\n");
        return -1;
    }
    avro_datum_decref(engine_rpm);

    *result = record;
    return 0;
}

#include "main.c"
