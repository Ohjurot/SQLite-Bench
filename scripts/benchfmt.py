"""
Formats the benchmark result
"""

import sys
import json

if __name__ == '__main__':
    # Argument processing
    if len(sys.argv) < 3:
        print("Usage: mox benchfmt <file_in> <file_out>")
        sys.exit()
    file_in = sys.argv[1]
    file_out = sys.argv[2]

    # Read file
    data = None
    with open(file_in) as f:
        data = json.load(f)
    if not data:
        print("Can't read input file!")
        sys.exit()

    # Process benchmarks
    result = dict()
    for benchmark in data["benchmarks"]:
        if benchmark["run_type"] == "aggregate":
            name = benchmark["name"].split("/")[-1]
            eval = name.split("_")[-1]
            favor = name.split("_")[-2]
            name = "_".join(name.split("_")[0:-2])

            if not name in result:
                result[name] = dict()
            if not favor in result[name]:
                result[name][favor] = dict()
            unit = "%"
            if benchmark["aggregate_unit"] == "time":
                result[name][favor][eval] = f"{float(benchmark['real_time']):.4f}{benchmark['time_unit']}"
            elif benchmark["aggregate_unit"] == "percentage":
                result[name][favor][eval] = f"{float(benchmark['real_time'] * 100):.4f}%"
            
            
    # Output formating
    if file_out.endswith('.json'):
        with open(file_out, 'w', encoding='utf-8') as f:
            json.dump(result, f, ensure_ascii=False, indent=4)
    elif file_out.endswith('.md'):
        with open(file_out, 'w', encoding='utf-8') as f:
            f.write('| Benchmark | Median (File) | Median (Memory) | CV% (File) | CV% (Memory) |\n')
            f.write('| --------- | ------------- | --------------- | ---------- | ------------ |\n')
            for r in result.keys():
                f.write(f'| **{r}** | {result[r]["file"]["median"]} | {result[r]["mem"]["median"]} | {result[r]["file"]["cv"]} | {result[r]["mem"]["cv"]} |\n')

