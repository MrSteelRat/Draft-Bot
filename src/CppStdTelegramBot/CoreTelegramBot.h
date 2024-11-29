#ifndef CORE_TELEGRAM_BOT_H
#define CORE_TELEGRAM_BOT_H

#include <tgbot/tgbot.h>
class CoreTelegramBot {
public:
  CoreTelegramBot();
  void start_bot();
  void base_command_bot();
  void get_question();
  ~CoreTelegramBot();

private:
  TgBot::Bot m_bot;
  std::string hello_msg;
  std::string URL_VK, URL_TELEGRAM, URL_GITHUB, URL_BOOSTY, URL_DONAT_ALERT;
  void load_config(const std::string& config_path);
};

#endif  // CORE_TELEGRAM_BOT_H
