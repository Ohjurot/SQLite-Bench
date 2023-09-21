#pragma once

#include "fixtures/f_sqlite_file_db.h"
#include "fixtures/f_sqlite_mem_db.h"

#include <ctime>
#include <cstdlib>
#include <sstream>

BENCHMARK_F(f_sqlite_file_db, sqlite_select_idx_file)(benchmark::State& s)
{
    std::srand(time(NULL));

    sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS _(k VARCHAR(36) NOT NULL, v VARCHAR(256) NOT NULL)", nullptr, nullptr, nullptr);
    sqlite3_exec(db, "CREATE INDEX IF NOT EXISTS _i ON _(k)", nullptr, nullptr, nullptr);
    sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    for (size_t i = 0; i < 1'000'000; i++)
    {
        std::stringstream ss;
        ss << "INSERT INTO _(k, v) VALUES ('K" << i << "','V" << i << "')";
        sqlite3_exec(db, ss.str().c_str(), nullptr, nullptr, nullptr);
    }
    sqlite3_exec(db, "COMMIT", nullptr, nullptr, nullptr);

    for (auto _ : s)
    {
        s.PauseTiming();
        const char* sql = nullptr;
        {
            std::stringstream ss;
            ss << "SELECT * FROM _ WHERE k = 'K" << std::rand() % 1'000'000 << "'";
            static std::string str;
            str = ss.str();
            sql = str.c_str();
        }
        s.ResumeTiming();
    
        sqlite3_exec(db, sql, nullptr, nullptr, nullptr);
    }
}

BENCHMARK_F(f_sqlite_mem_db, sqlite_select_idx_mem)(benchmark::State& s)
{
    std::srand(time(NULL));

    sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS _(k VARCHAR(36) NOT NULL, v VARCHAR(256) NOT NULL)", nullptr, nullptr, nullptr);
    sqlite3_exec(db, "CREATE INDEX IF NOT EXISTS _i ON _(k)", nullptr, nullptr, nullptr);
    sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    for (size_t i = 0; i < 1'000'000; i++)
    {
        std::stringstream ss;
        ss << "INSERT INTO _(k, v) VALUES ('K" << i << "','V" << i << "')";
        sqlite3_exec(db, ss.str().c_str(), nullptr, nullptr, nullptr);
    }
    sqlite3_exec(db, "COMMIT", nullptr, nullptr, nullptr);

    for (auto _ : s)
    {
        s.PauseTiming();
        const char* sql = nullptr;
        {
            std::stringstream ss;
            ss << "SELECT * FROM _ WHERE k = 'K" << std::rand() % 1'000'000 << "'";
            static std::string str;
            str = ss.str();
            sql = str.c_str();
        }
        s.ResumeTiming();

        sqlite3_exec(db, sql, nullptr, nullptr, nullptr);
    }
}

BENCHMARK_F(f_sqlite_file_db, sqlite_select_file)(benchmark::State& s)
{
    std::srand(time(NULL));

    sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS _(k VARCHAR(36) NOT NULL, v VARCHAR(256) NOT NULL)", nullptr, nullptr, nullptr);
    sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    for (size_t i = 0; i < 1'000'000; i++)
    {
        std::stringstream ss;
        ss << "INSERT INTO _(k, v) VALUES ('K" << i << "','V" << i << "')";
        sqlite3_exec(db, ss.str().c_str(), nullptr, nullptr, nullptr);
    }
    sqlite3_exec(db, "COMMIT", nullptr, nullptr, nullptr);

    for (auto _ : s)
    {
        s.PauseTiming();
        const char* sql = nullptr;
        {
            std::stringstream ss;
            ss << "SELECT * FROM _ WHERE k = 'K" << std::rand() % 1'000'000 << "'";
            static std::string str;
            str = ss.str();
            sql = str.c_str();
        }
        s.ResumeTiming();

        sqlite3_exec(db, sql, nullptr, nullptr, nullptr);
    }
}

BENCHMARK_F(f_sqlite_mem_db, sqlite_select_mem)(benchmark::State& s)
{
    std::srand(time(NULL));

    sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS _(k VARCHAR(36) NOT NULL, v VARCHAR(256) NOT NULL)", nullptr, nullptr, nullptr);
    sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);
    for (size_t i = 0; i < 1'000'000; i++)
    {
        std::stringstream ss;
        ss << "INSERT INTO _(k, v) VALUES ('K" << i << "','V" << i << "')";
        sqlite3_exec(db, ss.str().c_str(), nullptr, nullptr, nullptr);
    }
    sqlite3_exec(db, "COMMIT", nullptr, nullptr, nullptr);

    for (auto _ : s)
    {
        s.PauseTiming();
        const char* sql = nullptr;
        {
            std::stringstream ss;
            ss << "SELECT * FROM _ WHERE k = 'K" << std::rand() % 1'000'000 << "'";
            static std::string str;
            str = ss.str();
            sql = str.c_str();
        }
        s.ResumeTiming();

        sqlite3_exec(db, sql, nullptr, nullptr, nullptr);
    }
}
