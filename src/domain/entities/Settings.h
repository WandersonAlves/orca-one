#pragma once

#include <WString.h>
#include <map>
#include <FS.h>

#include "Language.h"
#include "Color.h"
#include "../../utility/FileUtility.h"

#define SETTINGS_FILE_NAME "/settings.json"

using namespace Utility;

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Domain::Entities
    {
        class Settings
        {
        private:
            String _deviceName;
            Language _language;
            Color _primaryColor;
            Color _backgroundColor;
            void deserialize(String jsonString);

        public:
            Settings() {}
            Settings(String jsonString);

            static Settings *fromFile(fs::FS &fs, const char *fileName);
            void save(fs::FS &fs, const char *fileName);

            String getDeviceName();
            void setDeviceName(String deviceName);
            Language getLanguage();
            void setLanguage(Language language);
            Color getPrimaryColor();
            void setPrimaryColor(Color color);
            Color getBackgroundColor();
            void setBackgroundColor(Color color);

            String serialize();
        };
    }
#ifdef __cplusplus
}
#endif