I=input;exec(int(I())*'a=I();b=I();l=len(a);print(l+len(b)-2*max(j-i for j in range(l+1)for i in range(j+1)if a[i:j]in b));')