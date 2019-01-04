#include <httpd.h>
#include <http_protocol.h>
#include <http_config.h>

static int hello_handler(request_rec *r)
{
    if (!r->handler || strcmp(r->handler, "hello")) {
        return DECLINED;
    }

    if (r->method_number != M_GET) {
        return HTTP_METHOD_NOT_ALLOWED;
    }

    ap_set_content_type(r, "text/html;charset=ascii");
    ap_rputs("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\">\n",
             r);
    ap_rputs("<html><head><title>Apache HelloWorld "
             "Module</title></head>", r);
    ap_rputs("<body><h1>Hello World!</h1>", r);
    ap_rputs("<p>This is the Apache HelloWorld module!</p>", r);
    ap_rputs("</body></html>", r);

    return OK;
}

static void hello_hooks(apr_pool_t *pool)
{
    ap_hook_handler(hello_handler, NULL, NULL, APR_HOOK_MIDDLE);
}

module AP_MODULE_DECLARE_DATA hello_module = {
        STANDARD20_MODULE_STUFF,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        hello_hooks
};
