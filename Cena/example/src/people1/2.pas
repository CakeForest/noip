var
  a,b: int64;

begin 
  assign(input,'2.in');
  reset(input);
  readln(a);
  readln(b);
  close(input);
 
  assign(output,'2.out');
  rewrite(output);
  writeln(a*b);
  close(output);
end.