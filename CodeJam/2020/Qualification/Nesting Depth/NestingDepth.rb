def read_line
    gets.chomp
end

def read_int
    read_line.to_i
end

def read_ints
    read_line.split(' ').map { |x| x.to_i }
end

def add_parentheses c
    n = c.to_i
    ('(' * n) + c + (')' * n)
end

def nest_parentheses s
    s.chars.map { |c| add_parentheses c }.join()
end

def remove_extra_parentheses s
    s.gsub(')(', '')
end

def main
    t = read_int
    
    t.times do |i|
        s = read_line
        current_string = prev_string = nest_parentheses(s)
        
        loop do
            current_string = remove_extra_parentheses(prev_string)

            break if current_string.length == prev_string.length
            
            prev_string = current_string
        end

        puts "Case ##{i + 1}: #{current_string}"
    end
end

if __FILE__ == $0
    main
end