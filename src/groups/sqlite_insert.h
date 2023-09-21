#pragma once

#include "fixtures/f_sqlite_file_db.h"
#include "fixtures/f_sqlite_mem_db.h"

BENCHMARK_F(f_sqlite_file_db, sqlite_insert_file)(benchmark::State& s)
{
    sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS _(k VARCHAR(36) NOT NULL, v VARCHAR(256) NOT NULL)", nullptr, nullptr, nullptr);
    
    for (auto _ : s)
    {
        sqlite3_exec(db, "INSERT INTO _(k, v) VALUES ('k','v')", nullptr, nullptr, nullptr);
    }
}

BENCHMARK_F(f_sqlite_mem_db, sqlite_insert_mem)(benchmark::State& s)
{
    sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS _(k VARCHAR(36) NOT NULL, v VARCHAR(256) NOT NULL)", nullptr, nullptr, nullptr);

    for (auto _ : s)
    {
        sqlite3_exec(db, "INSERT INTO _(k, v) VALUES ('k','v')", nullptr, nullptr, nullptr);
    }
}

BENCHMARK_F(f_sqlite_file_db, sqlite_insert_tr_file)(benchmark::State& s)
{
    sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS _(k VARCHAR(36) NOT NULL, v VARCHAR(256) NOT NULL)", nullptr, nullptr, nullptr);
    sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);

    for (auto _ : s)
    {
        sqlite3_exec(db, "INSERT INTO _(k, v) VALUES ('k','v')", nullptr, nullptr, nullptr);
    }

    sqlite3_exec(db, "COMMIT", nullptr, nullptr, nullptr);
}

BENCHMARK_F(f_sqlite_mem_db, sqlite_insert_tr_mem)(benchmark::State& s)
{
    sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS _(k VARCHAR(36) NOT NULL, v VARCHAR(256) NOT NULL)", nullptr, nullptr, nullptr);
    sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);

    for (auto _ : s)
    {
        sqlite3_exec(db, "INSERT INTO _(k, v) VALUES ('k','v')", nullptr, nullptr, nullptr);
    }

    sqlite3_exec(db, "COMMIT", nullptr, nullptr, nullptr);
}
