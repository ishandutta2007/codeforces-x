n,m=gets.split.map &:to_i;a=gets.split.map &:to_i;b=a[0,m];x=y=0;n.times{a=a.sort;x+=a[0];a[0]-=1;a=a[1..-1]if a[0]==0};n.times{b=b.sort;y+=b[-1];b[-1]-=1;b.pop if b[-1]==0};$><<[y,x]*' '