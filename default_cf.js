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

  return 0;
}
