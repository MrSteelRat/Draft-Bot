#include "CoreTelegramBot.h"

#include <yaml-cpp/yaml.h>
// We store the latest messages for each chat
std::map<std::int64_t, std::vector<std::int32_t>> chatMessageHistory;

// Function for deleting messages
void deleteMessagesBot(TgBot::Bot& bot, std::int64_t chatId) {
  if (chatMessageHistory.find(chatId) != chatMessageHistory.end()) {
    for (const auto& messageId : chatMessageHistory[chatId]) {
      try {
        bot.getApi().deleteMessage(chatId, messageId);
      } catch (const TgBot::TgException& e) {
        // Log if deletion failed
        std::cerr << "Failed to delete message " << messageId << ": "
                  << e.what() << std::endl;
      }
    }
    // Clearing the history for this chat
    chatMessageHistory[chatId].clear();
  }
}

CoreTelegramBot::CoreTelegramBot()
  : m_bot("x") {};

void CoreTelegramBot::start_bot() {
  try {
    TgBot::TgLongPoll longPoll(m_bot);
    while (true) {
      std::cout << "Long poll started" << std::endl;
      longPoll.start();
    }
  } catch (const TgBot::TgException& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  } catch (...) {
    std::cout << "error 2" << "\n";
  }
}

void CoreTelegramBot::load_config(const std::string& config_path) {
  YAML::Node config = YAML::LoadFile(config_path);
  // load hello msg
  hello_msg = config["hello_message"].as<std::string>();
  // load URL-adress
  URL_VK = config["urls"]["vk"].as<std::string>();
  URL_TELEGRAM = config["urls"]["telegram"].as<std::string>();
  URL_GITHUB = config["urls"]["github"].as<std::string>();
  URL_BOOSTY = config["urls"]["boosty"].as<std::string>();
  URL_DONAT_ALERT = config["urls"]["donat_alert"].as<std::string>();
}

void CoreTelegramBot::base_command_bot() {
  auto SendMessage = [this](
                       const std::string& command,
                       const std::string& url,
                       TgBot::Message::Ptr message) {
    m_bot.getApi().sendMessage(message->chat->id, url);
  };

  // Команда /start с приветственным сообщением
  m_bot.getEvents().onCommand("start", [this](TgBot::Message::Ptr message) {
    m_bot.getApi().sendMessage(message->chat->id, "Hi!");
  });

  m_bot.getEvents().onCommand(
    "github", [SendMessage](TgBot::Message::Ptr message) {
      SendMessage("github", "Github", message);
    });

  // m_bot.getEvents().onCommand(
  //   "telegram", [SendMessage](TgBot::Message::Ptr message) {
  //     SendMessage("tg", URL_TELEGRAM, message);
  //   });

  // m_bot.getEvents().onCommand(
  //   "donat_alert", [SendMessage](TgBot::Message::Ptr message) {
  //     SendMessage("donat_alert", URL_DONAT_ALERT, message);
  //   });

  // m_bot.getEvents().onCommand(
  //   "vk", [SendMessage](TgBot::Message::Ptr message) {
  //     SendMessage("vk", URL_VK, message);
  //   });

  m_bot.getEvents().onCommand("help", [this](TgBot::Message::Ptr message) {
    m_bot.getApi().sendMessage(
      message->chat->id,
      "Available commands: /start, /github, /tg, /donat_alert, /vk");
  });

  m_bot.getEvents().onAnyMessage([this](TgBot::Message::Ptr message) {
    printf("User wrote %s\n", message->text.c_str());
    if (StringTools::startsWith(message->text, "/start")) {
      return;
    }
  });
}
void CoreTelegramBot::get_question() {}

CoreTelegramBot::~CoreTelegramBot() {};
