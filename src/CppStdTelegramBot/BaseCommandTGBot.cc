#include "BaseCommandTGBot.h"

void BaseCommandTGBot::load_config(const std::string& config_path) {
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

void BaseCommandTGBot::base_command_telegram_bot() {
    auto SendMessage = [this](
                       const std::string& command,
                       const std::string& url,
                       TgBot::Message::Ptr message) {
        m_bot.getApi().sendMessage(message->chat->id, url);
    };

    // Команда /start с приветственным сообщением
    m_bot.getEvents().onCommand("start", [this](TgBot::Message::Ptr message) {
        int userId = message->chat->id;
        std::string username = message->chat->username;
        /*create_database_entry_user();*/
        m_bot.getApi().sendMessage(message->chat->id, hello_msg);
    });

    m_bot.getEvents().onCommand("github", [this, SendMessage](TgBot::Message::Ptr message) {
        SendMessage("github", URL_GITHUB, message);
    });

    m_bot.getEvents().onCommand("tg", [this, SendMessage](TgBot::Message::Ptr message) {
        SendMessage("tg", URL_TELEGRAM, message);
    });

    m_bot.getEvents().onCommand("donat_alert", [this, SendMessage](TgBot::Message::Ptr message) {
        SendMessage("donat_alert", URL_DONAT_ALERT, message);
    });

    m_bot.getEvents().onCommand("vk", [this, SendMessage](TgBot::Message::Ptr message) {
        SendMessage("vk", URL_VK, message);
    });

    m_bot.getEvents().onCommand("help", [this](TgBot::Message::Ptr message) {
        m_bot.getApi().sendMessage(message->chat->id, "Available commands: /start, /github, /tg, /donat_alert, /vk");
    });

    m_bot.getEvents().onAnyMessage([this](TgBot::Message::Ptr message) {
        printf("User wrote %s\n", message->text.c_str());
        if (StringTools::startsWith(message->text, "/start")) {
            return;
        }
    });
}
