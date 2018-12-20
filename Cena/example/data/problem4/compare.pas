program sort_compare;

const
  MAXN=5000;

var
  n: longint;
  s: array[1..MAXN]of longint;
  i: longint;
  bad: longint;
  x: longint;

  nn: longint;
  ss: array[1..MAXN]of longint;

  MaxScore: double;
  fscore, freport: text;

procedure Sort_s(l,h: longint);
var
  i,j: longint;
  p: longint;
begin 
  if l>=h then exit;
  i:=l;  j:=h;
  p:=s[i+random(j-i+1)];
  repeat
    while s[i]<p do inc(i);
    while p<s[j] do dec(j);
    if i<=j then begin 
      x:=s[i];  s[i]:=s[j];  s[j]:=x;
      inc(i);  dec(j);
    end;
  until j<i;
  Sort_s(l,j);
  Sort_s(i,h);
end;

begin
  val(paramstr(1),MaxScore,i);

  randomize;
  assign(input,'4.in');  reset(input);
  readln(n);
  for i:=1 to n do readln(s[i]);
  close(input);

  Sort_s(1,n);

  assign(freport,'report.log');  rewrite(freport);
  assign(fscore,'score.log');  rewrite(fscore);

  assign(input,'4.out');  reset(input);
  nn:=0;
  for i:=1 to n do begin
    if seekeof then break;
    inc(nn);
    readln(ss[i]);
  end;
  if not seekeof then begin
    writeln(fscore,0);
    writeln(freport,'Too long!');
  end else
    if nn<n then begin
      writeln(fscore,0);
      writeln(freport,'Too short!');
    end else begin
      bad:=0;
      for i:=1 to n do
        if s[i]<>ss[i] then inc(bad);
      if bad>=10 then begin
        writeln(fscore,0);
        writeln(freport,'错误太多了！不得分。');
        writeln(freport,'错误如下（共',bad,'处）：');
        bad:=0;
        for i:=1 to n do
          if s[i]<>ss[i] then begin 
            writeln(freport,' --- 第',i,'个数应该是：',s[i],' --- 而程序输出的是：',ss[i]);
            inc(bad);
            if bad=10 then break;
          end;
        writeln(freport,'......');
      end else 
        if bad=0 then begin
          writeln(fscore,MaxScore:0:0);
          writeln(freport,'Right');
        end else begin 
          writeln(fscore,MaxScore-bad:0:0);
          writeln(freport,'可以接受的错误，得部分分');
          writeln(freport,'错误如下（共',bad,'处）：');
          for i:=1 to n do
            if s[i]<>ss[i] then writeln(freport,' --- 第',i,'个数应该是：',s[i],' --- 而程序输出的是：',ss[i]);
        end;
    end;
  close(input);
  close(fscore);
  close(freport);
end.