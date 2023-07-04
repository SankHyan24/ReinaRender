#pragma once

namespace reina::util
{
    class Config
    {
    public:
        Config(int argc, char **argv);
        ~Config();
        void Parse();
        void PrintHelp();
        void PrintVersion();
        void PrintUsage();
        void PrintConfig();

    private:
    };
}