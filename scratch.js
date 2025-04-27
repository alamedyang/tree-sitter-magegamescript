const makeFarm = (name) => {
	let goatCount = 0;
	let taxRate = 0;
	return {
		get goatCount() {
			return goatCount;
		},
		set goatCount(n) {
			goatCount = n;
			taxRate = goatCount * 0.01;
			return goatCount;
		},
		log() {
			return `Farm ${name} has ${goatCount} goats at tax rate ${taxRate}`;
		},
	};
};

const gruffsFarm = makeFarm("Gruff's Farm");
const fawnsFarm = makeFarm("Fawn's Farm");
gruffsFarm.goatCount = 10;
fawnsFarm.goatCount = 100_000;

console.log(gruffsFarm.log());
console.log(fawnsFarm.log());

console.log("break");
