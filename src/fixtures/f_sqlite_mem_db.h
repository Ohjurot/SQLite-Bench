#pragma once

#include <benchmark/benchmark.h>

#include <sqlite3.h>

class f_sqlite_mem_db : public benchmark::Fixture
{
    public:
        sqlite3* db = nullptr;

    public:
        void SetUp(benchmark::State& st) 
        { 
            sqlite3_open_v2(nullptr, &db, SQLITE_OPEN_MEMORY, nullptr);
        }
        
        void TearDown(benchmark::State& st) 
        { 
            sqlite3_close(db);
        }
};
