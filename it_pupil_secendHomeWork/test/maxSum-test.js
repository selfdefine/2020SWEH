const assert = require('assert');

const maxSum = require('../maxSum');

describe('#maxSum.js', () => {

  describe('#maxSum()', () => {

    it('maxSum() should return 0', () => {
      assert.strictEqual(maxSum(), 0);
    });

    it('maxSum(-2,11,-4,13,-5,-2) should return 20', () => {
      assert.strictEqual(maxSum(-2, 11, -4, 13, -5, -2), 20);
    });

    it('maxSum(-1,-2,-3,-4,-5,-6) should return 0', () => {
      assert.strictEqual(maxSum(-1, -2, -3, -4, -5, -6), 0);
    });
  });
});