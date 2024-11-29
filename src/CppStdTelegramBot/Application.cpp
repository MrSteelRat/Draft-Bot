#include <cstdio>

#include "CoreTelegramBot.h"

int main() {
  CoreTelegramBot core;
  core.start_bot();
  core.base_command_bot();
  return 0;
}
