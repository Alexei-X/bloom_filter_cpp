import matplotlib.pyplot as plt
from numpy import ceil, log

def extract_points(line):
    x_arr = []
    y_arr = []
    pos = 0
    while True:
        if line[pos] == "[":
            c = line.index(",", pos)
            end_i = line.index("]", pos)
            x_arr.append(int(line[pos+1:c]))
            y_arr.append(int(line[c+1:end_i]))
            pos = end_i
        else:
            pos += 1
        if pos == len(line):
            break

    return x_arr, y_arr

def make_graph(line):
    i = line.index("(")
    j = line.index(")")
    separator = line.index(";")
    title = "Count of false positive for (m, n) = " + line[i:j+1]
    m = int(line[i+1:separator])
    n = int(line[separator+1:j])
    k = int(ceil(m/n*log(2)))
    x_values, y_values = extract_points(line)
    min_th = y_values[k-1]
    plt.figure().set_figwidth(10)
    plt.plot(x_values, y_values, 'ro')
    plt.xlabel("Number of functions k")
    plt.ylabel("Number of false positive for 5*n iterations")
    plt.plot(k, min_th, 'go', label="theoretical optimum")
    plt.legend()
    plt.title(title)
    plt.show()

if __name__ == "__main__":
    output_file_path = "false_pos.txt"
    with open(output_file_path, "r") as output_file:
        lines = output_file.read().splitlines()
        for line in lines:
            make_graph(line)

