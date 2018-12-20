uses
  libcheck;

var
  a,b,c,stc: string;

begin
  assign(input, '2.in'); { 试题的输入文件名，读取标准输入 }
  reset(input);
  readln(a);
  readln(b);
  close(input);
  assign(input, '2.out'); { 试题的输出文件名，由选手程序输出，读取选手输出 }
  reset(input);
  readln(c);
  close(input);
  read(std, stc); { 从标准输出文件中读取标准答案 }

  writeln(rep, '这个测试点的输入为：', a, ' ', b);
  writeln(rep, '标准输出为：', stc);
  writeln(rep, '选手输出为：', c);
  if stc=c then begin
    writeln(rep, '正确。');
    Score(fsco); { 得满分 }
  end
  else begin
    writeln(rep, '错误。');
    Score(0); { 得 0 分 }
  end;
  writeln(rep, '本校验程序由 *** 提供。仅供示例。');
  Finish;
end.