let ws = require('ws')                      // JSONのWS（WebSocket）パッケージの読み込み
var server = new ws.Server({port:8080});    // WebSocketサーバの生成 ～ ポート番号8080を利用
server.on('connection', ws => {             // WSサーバ機能の実行 ～ クライアント接続時に対応
    ws.on('message', message => {           // クライアントからのデータ受信（messageに格納）時に実行
    console.log(message.toString("utf8"));                   // 1) サーバの標準出力にmessageの内容表示
    ws.send(message.toString("utf8"));                       // 2) 送信クライアントのみにmessageの内容返信
    server.clients.forEach(client => {      // サーバ接続の全クライアントに対する処理の規定
        if (client !== ws)                  // 送信クライアントを除外する条件設定
        client.send(message.toString("utf8"));               // 3) 接続クライアントへのmessageの内容送信
        // ※ 表示で文字化けする場合 (message) の部分を全て (message.toString("utf8") ) に変更
        });
    });
    ws.on('close', () => {                  // 切断時に実行（例：ページのリロード）
    console.log('close');                   // サーバの標準出力に close と表示
    });
}); // 緑字：画面表示/メッセージ送信のWebSocket用メソッド