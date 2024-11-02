#ifndef BASE_COMMAND_TG_BOT_H
#define BASE_COMMAND_TG_BOT_H
#include <tgbot/tgbot.h>
#include <yaml-cpp/yaml.h>

#include <fstream>
#include <iostream>
#include <string>

class BaseCommandTGBot {
public:
  BaseCommandTGBot();
  void base_command_telegram_bot();
  ~BaseCommandTGBot();

private:
  TgBot::Bot m_bot;
  std::string hello_msg;
  std::string URL_VK, URL_TELEGRAM, URL_GITHUB, URL_BOOSTY, URL_DONAT_ALERT;
  void load_config(const std::string& config_path);
};
#endif  // BASE_COMMAND_TG_BOT_H