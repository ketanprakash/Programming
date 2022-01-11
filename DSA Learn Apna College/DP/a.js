document.querySelector('input').addEventListener('input', (event) => {
  document.querySelector('h1').innerHTML = event.target.value;
})