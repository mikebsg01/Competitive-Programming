def smartAssigning(names, statuses, projects, tasks)
    first = true
    minTasks = 0
    numOfProjects = 0
    person = ""
    names.each.with_index { |p, i|
        if not statuses[i] and (first or
            tasks[i] < minTasks or
            (tasks[i] == minTasks and projects[i] < numOfProjects))
            first = false
            minTasks = tasks[i]
            numOfProjects = projects[i]
            person = names[i]
        end
    }
    person
end
