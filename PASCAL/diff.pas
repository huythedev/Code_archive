uses math;
const fi='diff.INP';
      fo='diff.OUT';
var l,r,m,c,d,v,kq:int64;
begin
 assign(input,fi);reset(input);
 assign(output,fo);rewrite(output);
 read(l,r);kq:=1000000000000000000;
 d:=l;c:=r;
 while l<=r do
        begin
                m:=(l+r) div 2;
                if abs((d+m)*(m-d+1) div 2-(c+m+1)*(c-m) div 2)<kq then
                        begin
                             kq:=abs((d+m)*(m-d+1) div 2-(c+m+1)*(c-m) div 2);v:=m;
                        end;
                if (d+m)*(m-d+1) div 2<(c+m+1)*(c-m) div 2 then l:=m+1 else r:=m-1;
        end;
 writeln(v);
end.
