    unsigned char	o[SHA1_OUTPUT_LEN];
    template_CONTEXT	ctx;

    timestamp_t t0 = timestamp();

    template_INIT(&ctx);
    template_UPDATE(&ctx, buf, size);
    template_FINAL(&ctx, o);

    timestamp_t t1 = timestamp();

    report(template_NAME, o, t1-t0);

