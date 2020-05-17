#ifndef KlineCandlestickListener_hpp
#define KlineCandlestickListener_hpp

#include "Model.hpp"
#include "WSEventListener.hpp"

/**
 * Listener for Trade events
 */
class KlineCandlestickListener : public WSEventListener<Candlestick> {
public:

  KlineCandlestickListener(const std::shared_ptr<oatpp::data::mapping::ObjectMapper>& mapper)
    : WSEventListener<Candlestick>(mapper)
  {}

  void onEvent(const Candlestick::ObjectWrapper& obj) override {

    OATPP_LOGI("Kline/Candlesticks", "%s - startTime=%d, closeTime=%d / openPrice=%s, closePrice=%s, highPrice=%s, lowPrice=%s",
      obj->symbol->c_str(),
      *obj->kline->klineStartTime,
      *obj->kline->klineCloseTime,
      obj->kline->openPrice->c_str(),
      obj->kline->closePrice->c_str(),
      obj->kline->highPrice->c_str(),
      obj->kline->lowPrice->c_str()
    );

  }

};

#endif // KlineCandlestickListener_hpp
