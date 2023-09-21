#pragma once

#include <benchmark/benchmark.h>

#include <sqlite3.h>

#include <filesystem>

class f_sqlite_file_db : public benchmark::Fixture
{
    public:
        sqlite3* db = nullptr;

    public:
        void SetUp(benchmark::State& st) 
        { 
            sqlite3_open("./temp.db", &db);
        }
        
        void TearDown(benchmark::State& st) 
        { 
            sqlite3_close(db);
            std::filesystem::remove("./temp.db");
        }
};
