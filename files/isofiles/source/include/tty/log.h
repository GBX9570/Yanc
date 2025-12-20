#ifndef LOG_H
#define LOG_H

void ok(const char *s);
void fail(const char *s);
void fatal_impl(const char *s, const char *file, int line);

#define fatal(msg) fatal_impl(msg, __FILE__, __LINE__);

#endif