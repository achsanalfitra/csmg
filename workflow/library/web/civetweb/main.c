#include "civetweb.h"
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

int my_file_handler(struct mg_connection *conn, void *cbdata) {
  mg_send_file(conn, "another_file.html");
  return 1;
}

int log_message(const struct mg_connection *conn, const char *message) {
  puts(message);
  return 1;
}

int main() {
  struct mg_context *g_ctx;
  struct mg_callbacks callbacks;
  const char *options[] = {
      "document_root",
      "path/to/this/root", // IMPORTANT, PROVIDE PATH TO THE ROOT DOCUMENT
      "listening_ports",
      "8080",
      "request_timeout_ms",
      "10000",
      "error_log_file",
      "error.log",
      "enable_auth_domain_check",
      "no",
      0,
  };

  memset(&callbacks, 0, sizeof(callbacks));

  callbacks.log_message = log_message;

  g_ctx = mg_start(&callbacks, 0, options);

  if (g_ctx == NULL) {
    printf("error detected");
    return 1;
  }

  mg_set_request_handler(g_ctx, "/my_file", my_file_handler, 0);

  while (1) {
#ifdef _WIN32
    Sleep(1000);
#else
    sleep(1);
#endif
  }

  mg_stop(g_ctx);

  return 0;
}