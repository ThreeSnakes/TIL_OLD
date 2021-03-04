# [ETC] Appsflyer Cost Encryption 정리

AppsFlyer Cost Integration연동 작업중 Cost Encryption 방법을 정리해놓는다.

- AppsFlyer Cost Encrytion
  - use the AES algorithm, with an ECB block mode, using PKCS5 padding. Then they must Base 64 encode the encrypted data, and finally URL encode the result.
  - [관련 문서](https://support.appsflyer.com/hc/en-us/articles/115000748446-Cost-sharing-for-ad-networks)

## 코드

``` js
const crypto = require('crypto');
const APPSFLYER_ENCRYPTION_KEY = "";/*AppsFlyer에서 받은 키를 입력*/

const encryptCostInfo = ( params = {} ) => {
  const { cost = 0, currency = "USD", model = 'CPI' } = params;
  const query = `af_cost_currency=${currency}&af_cost_model=${model}&af_cost_value=${cost}`;

  const cipher = crypto.createCipheriv('aes-128-ecb', APPSFLYER_ENCRYPTION_KEY, Buffer.alloc(0));
  let encryptedString = cipher.update(query, 'utf8', 'base64');
  encryptedString += cipher.final('base64');

  return encodeURIComponent(encryptedString);
};
```
