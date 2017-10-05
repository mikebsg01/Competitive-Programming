require 'date'

def day(date)
    if (date.instance_of?(Date))
        date.strftime("%A")
    end
end

def next_week(date)
    if (date.instance_of?(Date))
        date + (7 - date.wday)
    end
end

def next_wday(date, x)
    if (date.instance_of?(Date))
        (x > date.wday) ? (date + (x - date.wday)) : (next_week(date) + x)
    end
end

def recurringTask(firstDate, k, daysOfTheWeek, n)
  dates = []
  current_date = Date.strptime(firstDate, "%d/%m/%Y")
  indexOfTheDays = daysOfTheWeek.collect { |x| Date::DAYNAMES.index(x) }.sort
  starts = daysOfTheWeek.index(day(current_date))
  ends = starts - 1
  sequence = indexOfTheDays[starts...daysOfTheWeek.size] | indexOfTheDays[0..ends]
  taken = distance = 0

  i = 0
  while i < sequence.size and taken < n
    dates.push(current_date)
    taken += 1
    i += 1
    current_date = next_wday(current_date, sequence[i % sequence.size])
  end

  i = 0
  while taken < n
    dates.push(dates[i] + (7 * k))
    i += 1
    taken += 1
  end

  dates.collect { |d| d.strftime("%d/%m/%Y") }
end

puts recurringTask("01/01/2015", 2, ["Monday", "Thursday"], 4).inspect