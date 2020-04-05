def read_line
    gets.chomp
end

def read_int
    read_line.to_i
end

def read_ints
    read_line.split(' ').map { |x| x.to_i }
end

class Pair
    attr_reader :x, :y
  
    def initialize(x, y)
      @x = x
      @y = y
    end

    def inspect 
        "Pair(#{@x}, #{@y})"
    end
end

def schedules_overlap?(a, b)
    a.y > b.x
end

def take_longest_schedule_possible s
    current_schedule = Pair.new -1, -1

    s.reject do |activity_schedule|
        overlap = schedules_overlap?(current_schedule, activity_schedule)
        current_schedule = overlap ? current_schedule : activity_schedule
        overlap
    end
end

def is_valid_schedule? s
    current_schedule = Pair.new -1, -1

    s.all? do |activity_schedule|
        overlap = schedules_overlap?(current_schedule, activity_schedule)
        current_schedule = activity_schedule
        not overlap
    end
end

def format_solution s, c, j
    s.map { |x| c.include?(x) ? 'C' : 'J' }.join('')
end

def main
    t = read_int
    
    t.times do |i|
        n = read_int
    
        activity_schedules = n.times.to_a.map do |x|
            activity_schedule = read_ints
            Pair.new *activity_schedule
        end

        sorted_activity_schedules = activity_schedules.sort_by { |p| p.x }
        cameron_schedule = take_longest_schedule_possible(sorted_activity_schedules)
        jamie_schedule = sorted_activity_schedules - cameron_schedule

        print "Case ##{i + 1}: "
        
        if is_valid_schedule?(jamie_schedule)
            puts format_solution(activity_schedules, cameron_schedule, jamie_schedule)
        else
            puts "IMPOSSIBLE"
        end
    end
end

if __FILE__ == $0
    main
end