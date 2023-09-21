# SQLite-Bench
This is a small project that aims to compare several SQLite features.

The following benchmarks are performed (For both in-memory and on disk DBs):
- Create Table
- Insert record
- Select with index
- Select without index

On my machine I get the following results (100 Iterations):
| Benchmark | Median (File) | Median (Memory) | CV% (File) | CV% (Memory) |
| --------- | ------------- | --------------- | ---------- | ------------ |
| **sqlite_create** | 32745.6197ns | 610.0610ns | 7.8199% | 2.4354% |
| **sqlite_insert** | 4802564.1071ns | 7.5097ns | 4.1612% | 3.3174% |
| **sqlite_insert_tr** | 1302.2026ns | 7.2580ns | 3.1744% | 3.9168% |
| **sqlite_select_idx** | 46400.9548ns | 623.2228ns | 4.5986% | 2.8667% |
| **sqlite_select** | 62900581.8183ns | 608.5350ns | 9.6660% | 4.1962% |

> Windows 10: 12x Intel @ 2592MHz


This project uses sqlite and google benchmark.
