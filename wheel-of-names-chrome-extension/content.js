function triggerWheelSpin() {
    // Wait for the wheel to load, then trigger the spin
    setTimeout(() => {
      const spinButton = document.querySelector('.wheel__spin');
      if (spinButton) {
        spinButton.click();  // Trigger the spin
      }
    }, 2000); // Wait a bit to make sure the wheel is loaded
  }
  