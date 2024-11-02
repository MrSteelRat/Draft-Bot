#ifndef CORE_TELEGRAM_BOT_H
#define CORE_TELEGRAM_BOT_H

#include <tgbot/tgbot.h>

#include "BaseCommandTGBot.h"

extern BaseCommandTGBot baseCommandTGBot;

class CoreTelegramBot {
public:
  CoreTelegramBot();
  void start();
  ~CoreTelegramBot();

private:
  TgBot::Bot m_bot;
};

#endif  // CORE_TELEGRAM_BOT_H
