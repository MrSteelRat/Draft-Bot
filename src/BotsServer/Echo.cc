#include "Echo.h"

Echo::Echo(
    const components::ComponentConfig& config,
    const components::ComponentContext& context
) :
    TcpAcceptorBase(config, context),
    stats_(context.FindComponent<components::StatisticsStorage>()
        .GetMetricsStorage()->GetMetric(kTcpEchoTag))
{
}
