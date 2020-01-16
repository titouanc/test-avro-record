int main(int argc, const char **argv)
{
    (void) argc;
    (void) argv;

    // Load schema
    char schema_json_string[4096];
    strncpy(schema_json_string, SCHEMA, sizeof(schema_json_string));
    avro_schema_t schema;
    if (avro_schema_from_json(schema_json_string, 0, &schema, NULL)){
        fprintf(stderr, "Unable to load Avro schema: %s\n", avro_strerror());
        return -1;
    }

    // Open output file
    char output_path[256];
    snprintf(output_path, sizeof(output_path), "%s.avro", argv[0]);
    avro_file_writer_t writer;
    if (avro_file_writer_create_with_codec(output_path, schema, &writer, "null", 0)){
        fprintf(stderr, "Unable to create output file: %s\n", avro_strerror());
        return -1;
    }

    avro_datum_t record;
    if (create_record(schema, &record)){
        fprintf(stderr, "Cannot create record.\n");
        return -1;
    }

    if (avro_file_writer_append(writer, record)){
        fprintf(stderr, "Unable to write Avro record to file: %s\n", avro_strerror());
        return -1;
    }

    // Cleanup
    avro_datum_decref(record);
    avro_file_writer_close(writer);
    avro_schema_decref(schema);
    return 0;
}
