#ifndef LOG_H_
#define LOG_H_

#define DEBUG

#define DEBUG_INFO 1
#define DEBUG_TEST 2

#ifdef DEBUG

#define LOG_INIT() Serial.begin(115200)
#define LOG_PRINT(TYPE, MSG) if (TYPE == DEBUG_INFO) Serial.print(MSG)
#define LOG_PRINTLN(TYPE, MSG) if (TYPE == DEBUG_INFO) Serial.println(MSG)
//#define LOG_PRINTLN(TYPE, ...) if (TYPE == DEBUG_INFO) Serial.println(__VA_ARGS__)

#else

#define LOG_INIT()
#define LOG_PRINT(TYPE, MSG)
#define LOG_PRINTLN(TYPE, MSG)
//#define LOG_PRINTLN(TYPE, ...)

#endif

#endif
