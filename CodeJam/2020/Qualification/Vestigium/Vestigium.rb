def read_line
    gets.chomp
end

def read_int
    read_line.to_i
end

def read_ints
    read_line.split(' ').map { |x| x.to_i }
end

def sum_diagonal m
    m.map
        .with_index { |x, i| x[i] }
        .inject(0) { |sum, x| sum + x }
end

def count_invalid_rows m
    m.count do |a|
        a.size != a.uniq.size
    end
end

def count_invalid_columns m
    n = m.size

    n.times.to_a.count do |i|
        column = m.collect { |r| r[i] }
        column.size != column.uniq.size
    end
end

def main
    t = read_int
    
    t.times do |i|
        n = read_int
        m = []

        n.times do |j|
            m << read_ints
        end

        k = sum_diagonal m
        r = count_invalid_rows m.clone
        c = count_invalid_columns m.clone

        puts "Case ##{i + 1}: #{k} #{r} #{c}"
    end
end

if __FILE__ == $0
    main
end