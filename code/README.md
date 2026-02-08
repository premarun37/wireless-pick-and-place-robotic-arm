<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Expense Tracker</title>

<style>
:root{
  --bg:#0b0f1a;
  --card:#121a2b;
  --accent:#18e0b5;
  --text:#e6edf3;
  --muted:#8b95a7;
  --red:#ff5c5c;
  --green:#2bd576;
}
*{box-sizing:border-box;font-family:system-ui}
body{margin:0;background:var(--bg);color:var(--text)}
.app{max-width:430px;margin:auto;min-height:100vh;padding:16px;padding-bottom:90px}
h1,h2,h3{margin:0 0 10px}
.small{color:var(--muted);font-size:13px}

.card{
  background:linear-gradient(180deg,#121a2b,#0e1424);
  border-radius:18px;
  padding:16px;
  margin-bottom:14px;
}
.row{display:flex;justify-content:space-between;align-items:center;gap:10px}
.hidden{display:none}

.badge{
  background:#1c2540;
  padding:6px 12px;
  border-radius:20px;
  font-size:12px;
  color:var(--accent)
}

/* bottom nav */
nav{
  position:fixed;bottom:0;left:0;right:0;
  background:#0e1424;border-top:1px solid #1c2540;
  display:flex;justify-content:space-around;padding:10px 0
}
nav button{
  background:none;border:none;color:var(--muted);font-size:12px
}
nav button.active{color:var(--accent)}

/* fab */
.fab{
  position:fixed;bottom:70px;right:20px;
  width:56px;height:56px;border-radius:50%;
  background:var(--accent);color:#000;
  border:none;font-size:30px
}
</style>
</head>

<body>
<div class="app">

<!-- HOME -->
<section id="home">
<h1>Current Month</h1>
<p class="small">Your expense summary</p>

<div class="card">
  <div class="small">Monthly Balance</div>
  <h2 class="small">No data yet</h2>
</div>

<div class="row">
  <div class="card" style="flex:1">
    <div class="small">Income</div>
    <h3 class="small">₹0</h3>
  </div>
  <div class="card" style="flex:1">
    <div class="small">Expenses</div>
    <h3 class="small">₹0</h3>
  </div>
</div>

<div class="card">
<h2>Spending by Category</h2>
<p class="small">No expenses recorded</p>
</div>

<div class="card">
<h2>Recent Transactions</h2>
<p class="small">No transactions yet</p>
</div>
</section>

<!-- ANALYTICS -->
<section id="analytics" class="hidden">
<h1>Analytics</h1>
<p class="small">No data available</p>

<div class="card">
<p class="small">Start adding expenses to see analytics</p>
</div>
</section>

<!-- HISTORY -->
<section id="history" class="hidden">
<h1>Expense History</h1>

<div class="card">
<p class="small">No monthly history available</p>
</div>
</section>

<!-- SETTINGS -->
<section id="settings" class="hidden">
<h1>Settings</h1>

<div class="card">
<h2>Native Features</h2>
<p class="small">
This Android app can read Bank SMS and auto-add expenses.
</p>
</div>

<div class="card">
<h2>Bank SMS</h2>
<button onclick="importSMS()" style="
width:100%;
padding:12px;
border-radius:10px;
border:none;
background:var(--accent);
color:#000;
font-weight:bold;">
Import Bank SMS
</button>
</div>

<div class="card">
<h2>Data & Privacy</h2>
<div class="row"><span>Local Storage</span><span class="green">●</span></div>
<div class="row"><span>Privacy</span><span class="green">●</span></div>
</div>
</section>

</div>

<button class="fab">+</button>

<nav>
<button onclick="show('home')" class="active">Home</button>
<button onclick="show('analytics')">Analytics</button>
<button onclick="show('history')">History</button>
<button onclick="show('settings')">Settings</button>
</nav>

<script>
function show(id){
  document.querySelectorAll("section").forEach(s=>s.classList.add("hidden"))
  document.getElementById(id).classList.remove("hidden")
  document.querySelectorAll("nav button").forEach(b=>b.classList.remove("active"))
  event.target.classList.add("active")
}

/* ====== ANDROID SMS BRIDGE ====== */

window.onSMSReceived = function (sms) {
  alert("Bank SMS:\n" + sms);
  console.log("Received:", sms);
};

function importSMS() {
  if (window.AndroidSMS) {
    AndroidSMS.requestBankSMS();
  } else {
    alert("SMS reading works only inside Android app");
  }
}
</script>

</body>
</html>