#pragma once

#include "fixtures/f_sqlite_file_db.h"
#include "fixtures/f_sqlite_mem_db.h"

#include <string>
#include <vector>
#include <sstream>

BENCHMARK_F(f_sqlite_file_db, sqlite_create_file)(benchmark::State& s)
{
    size_t i = 0;
    for (auto _ : s)
    {
        s.PauseTiming();
        const char* sql = nullptr;
        {
            static std::string str;
            std::stringstream ss;
            ss << "CREATE TABLE IF NOT EXISTS _" << i << "(k VARCHAR(36) PRIMARY KEY NOT NULL, v VARCHAR(256) NOT NULL)";
            str = ss.str();
            sql = str.c_str();
        }
        s.ResumeTiming();

        sqlite3_exec(db, sql, nullptr, nullptr, nullptr);
    }
}

BENCHMARK_F(f_sqlite_mem_db, sqlite_create_mem)(benchmark::State& s)
{
    size_t i = 0;
    for (auto _ : s)
    {
        s.PauseTiming();
        const char* sql = nullptr;
        {
            static std::string str;
            std::stringstream ss;
            ss << "CREATE TABLE IF NOT EXISTS _" << i << "(k VARCHAR(36) PRIMARY KEY NOT NULL, v VARCHAR(256) NOT NULL)";
            str = ss.str();
            sql = str.c_str();
        }
        s.ResumeTiming();

        sqlite3_exec(db, sql, nullptr, nullptr, nullptr);
    }
}
