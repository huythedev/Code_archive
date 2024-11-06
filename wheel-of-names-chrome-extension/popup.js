document.getElementById('goButton').addEventListener('click', function() {
    const namesInput = document.getElementById('names').value.trim();
    const chosenName = document.getElementById('chosenName').value;
  
    // Validate input
    if (!namesInput || !chosenName) {
      alert('Please enter the names and select a person.');
      return;
    }
  
    // Get the names from the input
    const namesArray = namesInput.split(',').map(name => name.trim());
    if (!namesArray.includes(chosenName)) {
      alert('The selected name must be in the list.');
      return;
    }
  
    // Construct the Wheel of Names URL with only the chosen person
    const url = new URL('https://wheelofnames.com/');
    url.searchParams.set('names', chosenName);
  
    // Open the Wheel of Names with the selected name
    chrome.tabs.create({ url: url.toString() }, function(tab) {
      // Inject content.js to trigger the spin automatically
      chrome.scripting.executeScript({
        target: { tabId: tab.id },
        func: triggerWheelSpin
      });
    });
  });
  
  function populateNames() {
    const namesInput = document.getElementById('names').value.trim();
    if (namesInput) {
      const namesArray = namesInput.split(',').map(name => name.trim());
      const selectElement = document.getElementById('chosenName');
      selectElement.innerHTML = '';
      namesArray.forEach(name => {
        const option = document.createElement('option');
        option.value = name;
        option.textContent = name;
        selectElement.appendChild(option);
      });
    }
  }
  
  document.getElementById('names').addEventListener('input', populateNames);
  