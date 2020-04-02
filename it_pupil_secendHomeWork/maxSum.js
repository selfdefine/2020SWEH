function maxSum (...rest) {
  let sum = rest[0] || 0;
  let max = sum
  rest.map((d, i) => {
    if (i != 0)
      sum + d < d ? sum = d : sum += d;
    if (sum > max)
      max = sum;
  })
  return max < 0 ? 0 : max;
}

const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});
var inputArr = [];
rl.on('line', function (input) {
  inputArr = input.split(" ");
  inputArr.forEach(function (item, index) {
    inputArr[index] = +item;// 转化为数字  
  });
  // 下面就可以对数据进行处理......  
  let smax = maxSum(...inputArr);
  console.log(smax)
  inputArr = [];// 清空数组  
  rl.close();
});

rl.on('close', function () {
  process.exit(0);
});

module.exports = maxSum 