#include <userver/components/common_server_component_list.hpp>

namespace samples::tcp::echo
{
    struct Stats;

    class Echo final : public components::TcpAcceptorBase
    {
    public:
        static constexpr std::string_view kName = "tcp-echo";

        // Component is valid after construction and is able to accept requests
        Echo(
            const components::ComponentConfig& config,
            const components::ComponentContext& context);

        void ProcessSocket(engine::io::Socket&& sock) override;

    private:
        Stats& stats_;
    };
} // namespace samples::tcp::echo

namespace samples::tcp::echo
{
    struct Stats
    {
        std::atomic<std::uint64_t> opened_sockets{0};
        std::atomic<std::uint64_t> closed_sockets{0};
        std::atomic<std::uint64_t> bytes_read{0};
    };
}
