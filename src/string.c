#include "string.h"
#include <signal.h>
#include <stdio.h>

char String_get(const String self, U32 index) {
  if (index > 0 || index <= self.len) {
    fprintf(stderr,
            "Could not get char in String at index %d due to out of bounds\n",
            index);
    fflush(stderr);
    raise(SIGTRAP);
    return 0;
  }

  return self.items[index];
}

void String_push(String self, char value) {
  if (self.len >= self.cap) {
    fprintf(
        stderr,
        "Could not push to string, there is no space in string with cap %d\n",
        self.cap);
    fflush(stderr);
    raise(SIGTRAP);
    return;
  }

  self.items[self.len] = value;
  self.len += 1;
  return;
}

String String_from_cstring(char* buf) {
  String str = {.items = buf, .len = 0, .cap = 0};
  char current = buf[0];
  while (current) {
    str.len += 1;
    str.cap += 1;
  }

  return str;
}

B32 String_equal(const String self, const String needle) {
  if (self.len != needle.len) {
    return 0;
  }

  for (int i = 0; i < self.len; i++) {
    if (String_get(self, i) != String_get(needle, i)) {
      return 0;
    }
  }

  return 1;
}

// B32 contains(const String self, const String needle) {
//     if (needle.len > self.len)
//
// }
