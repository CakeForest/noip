{$I-,Q-,R-,S-}
var
  n,i,x,sum: integer;

begin
  sum:=0;
  assign(input,'1.in');
  reset(input);
  readln(n);
  for i:=1 to n do begin
    read(x);
    sum:=sum+x;
  end;
  close(input);

  assign(output,'1.out');
  rewrite(output);
  writeln(sum);
  close(output);
end.
