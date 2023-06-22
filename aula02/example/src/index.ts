const altitudeSet = new Map();
altitudeSet.set("low", 1);
altitudeSet.set("medium", 0.5);
altitudeSet.set("high", 0);

const climateRegionSet = new Map();
climateRegionSet.set("equatorial", 1.0);
climateRegionSet.set("subtropical", 0.5);
climateRegionSet.set("polar", 0.0);

const civilizationLevelSet = new Map();
civilizationLevelSet.set("big city", 1.0);
civilizationLevelSet.set("medium city", 0.75);
civilizationLevelSet.set("small city", 0.5);
civilizationLevelSet.set("farm", 0.0);

const dayTimeSet = new Map();
dayTimeSet.set("morning", 0.35);
dayTimeSet.set("mid day", 0.75);
dayTimeSet.set("afternoon", 1.0);
dayTimeSet.set("evening", 0.5);
dayTimeSet.set("night", 0.0);

type Answer = {
    altitude: string,
    climateRegion: string,
    civilizationLevel: string,
    dayTime: string,
}

function fuzzyPertinenceInfer(altitude: number, 
    climateRegion: number, civilizationLevel: number, 
    dayTime: number): number{
    
    return (altitude + climateRegion + civilizationLevel + dayTime) / 4; 
}

function temperatureInfer(pertinence: number) : string{
    if(pertinence < 0.25){
        return "cold";
    }
    else if(pertinence < 0.75){
        return "warm";
    }
    else{
        return "hot";
    }
}

function decideTemperature(answer: Answer) : string {
    const altitudePertinence = altitudeSet.get(answer.altitude);
    const climateRegionPertinence = climateRegionSet.get(answer.climateRegion);
    const civilizationLevelPertinence = civilizationLevelSet.get(answer.civilizationLevel);
    const dayTimePertinence = dayTimeSet.get(answer.dayTime);

    const pertinence = fuzzyPertinenceInfer(altitudePertinence, climateRegionPertinence,
            civilizationLevelPertinence, dayTimePertinence);

    console.log("Pertinence: ", pertinence);

    return temperatureInfer(pertinence);
}

// const answers = {
//     altitude: "medium",
//     climateRegion: "equatorial",
//     civilizationLevel: "big city",
//     dayTime: "morning",
// };

const answers = {
    altitude: "high",
    climateRegion: "subtropical",
    civilizationLevel: "small city",
    dayTime: "night",
};

console.log(decideTemperature(answers));