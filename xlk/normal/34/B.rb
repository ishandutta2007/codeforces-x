n,m=gets.split.map &:to_i;p -eval((gets.split.map(&:to_i)+[0]*m).sort()[0...m]*'+')