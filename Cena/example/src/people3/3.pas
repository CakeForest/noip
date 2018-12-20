var
  n,i,x: integer;
  s: array[1..5000]of integer;

procedure Sort;
var
  i: integer;
  ok: boolean;
begin 
  repeat
    ok:=true;
    for i:=1 to n-1 do 
      if s[i]>s[i+1] then begin 
        x:=s[i];  s[i]:=s[i+1];  s[i+1]:=x;
        ok:=false;
      end;
  until ok;
end;

begin 
  assign(input,'3.in');  
  reset(input);
  readln(n);
  for i:=1 to n do readln(s[i]);
  close(input);

  Sort;
  x:=s[1];  s[1]:=s[n];  s[n]:=x;
  
  assign(output,'3.out');
  rewrite(output);
  for i:=1 to n do writeln(s[i]);
  close(output);
end.
    