// Problem #    : 71A
// Created on   : 2019-01-15 00:50:50
process.stdin.resume();
process.stdin.setEncoding("utf8");

var input = "",
  readline,
  print;

process.stdin.on("data", function(chunk) {
  input += chunk;
});

process.stdin.on("end", function() {
  input = input.split(/\r?\n/);
  print = function(data) {
    process.stdout.write(data + "\n");
  };
  var inputLineIndex = 0;
  readline = function() {
    return inputLineIndex >= input.length ? undefined : input[inputLineIndex++];
  };
  process.exit(main() || 0);
});

function main() {
  // Your code here

  let n = Number(readline());
  for (let i = 0; i < n; i++) {
      let str = readline();
      if (str.length > 10) {
          let ans = str[0] + (str.length - 2).toString() + str[str.length - 1];
          print(ans);
          continue;
      }
      print(str);
  }

  return 0;
}
