package dev.ia.avaliation_1;

import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class Avaliation_1 {

    private static Map<String, Float> velocitySet, supportSet, maintenanceSet, documentationSet, writingSet, librarySet;

    public static void execute() {

        velocitySet = new LinkedHashMap<>();
        velocitySet.put("Muito ruim", 1.0F);
        velocitySet.put("Ruim", 2.0F);
        velocitySet.put("Medio", 3.0F);
        velocitySet.put("Boa", 4.0F);
        velocitySet.put("Muito boa", 5.0F);

        supportSet = new LinkedHashMap<>();
        supportSet.put("Muito ruim", 1.0F);
        supportSet.put("Ruim", 2.0F);
        supportSet.put("Medio", 3.0F);
        supportSet.put("Boa", 4.0F);
        supportSet.put("Muito boa", 5.0F);

        maintenanceSet = new LinkedHashMap<>();
        maintenanceSet.put("Muito ruim", 1.0F);
        maintenanceSet.put("Ruim", 2.0F);
        maintenanceSet.put("Medio", 3.0F);
        maintenanceSet.put("Boa", 4.0F);
        maintenanceSet.put("Muito boa", 5.0F);

        documentationSet = new LinkedHashMap<>();
        documentationSet.put("Muito ruim", 1.0F);
        documentationSet.put("Ruim", 2.0F);
        documentationSet.put("Medio", 3.0F);
        documentationSet.put("Boa", 4.0F);
        documentationSet.put("Muito boa", 5.0F);

        writingSet = new LinkedHashMap<>();
        writingSet.put("Muito ruim", 1.0F);
        writingSet.put("Ruim", 2.0F);
        writingSet.put("Medio", 3.0F);
        writingSet.put("Boa", 4.0F);
        writingSet.put("Muito boa", 5.0F);

        librarySet = new LinkedHashMap<>();
        librarySet.put("Muito ruim", 1.0F);
        librarySet.put("Ruim", 2.0F);
        librarySet.put("Medio", 3.0F);
        librarySet.put("Boa", 4.0F);
        librarySet.put("Muito boa", 5.0F);

        int levels = 0;
        Response response = new Response();

        try (Scanner scanner = new Scanner(System.in)) {
            while (phase(++levels, scanner, response)) ;
        }

        System.out.println("Sua resposta foi: ");
        System.out.println(" ");
        System.out.println("Velocidade: " + response.getVelocity());
        System.out.println("Biblioteca: " + response.getLibrary());
        System.out.println("Documentação: " + response.getDocumentation());
        System.out.println("Suporte: " + response.getSupport());
        System.out.println("Escrita: " + response.getWriting());
        System.out.println("Manutenção: " + response.getMaintenance());
        System.out.println(" ");
        System.out.println("Com base nisso, está sendo gerado a sua linguagem ideal!");
        System.out.println(" ");

        Executors.newSingleThreadScheduledExecutor().scheduleWithFixedDelay(() -> {

            try {
                System.out.println(decideLang(response));
            } catch (Throwable e) {
                e.printStackTrace();
            }

        }, 1, 5, TimeUnit.SECONDS);

    }

    private static boolean phase(int level, Scanner scanner, Response response) {

        if (level == 1) {

            System.out.println(" ");
            System.out.println("Qual velocidade você espera da linguagem?:");

            for (String key : velocitySet.keySet())
                System.out.println(key);

            System.out.println(" ");

            response.setVelocity(scanner.nextLine());

        } else if (level == 2) {

            System.out.println(" ");
            System.out.println("Qual a facilidade de escrita você deseja?:");

            for (String key : writingSet.keySet())
                System.out.println(key);

            System.out.println(" ");

            response.setWriting(scanner.nextLine());

        } else if (level == 3) {

            System.out.println(" ");
            System.out.println("Qual a qualidade de suporte ao código você deseja?:");

            for (String key : supportSet.keySet())
                System.out.println(key);

            System.out.println(" ");

            response.setSupport(scanner.nextLine());

        } else if (level == 4) {

            System.out.println(" ");
            System.out.println("Qual a qualidade de manuntenção ao código você deseja?:");

            for (String key : maintenanceSet.keySet())
                System.out.println(key);

            System.out.println(" ");

            response.setMaintenance(scanner.nextLine());

        } else if (level == 5) {

            System.out.println(" ");
            System.out.println("Qual a atualização e leitura você espera da documentação?:");

            for (String key : documentationSet.keySet())
                System.out.println(key);

            System.out.println(" ");

            response.setDocumentation(scanner.nextLine());

        } else if (level == 6) {

            System.out.println(" ");
            System.out.println("Qual a variedade e qualidade das bibliotecas nativas você deseja?:");

            for (String key : librarySet.keySet())
                System.out.println(key);

            System.out.println(" ");

            response.setLibrary(scanner.nextLine());

        } else {
            return false;
        }

        return true;

    }

    private static float calcPertinence(float... args) {

        float calc = 0.0F;

        for (float arg : args)
            calc += arg;

        return calc / args.length;
    }

    private static String decideLang(Response response) {

        float velocity = velocitySet.get(response.getVelocity());
        float writing = writingSet.get(response.getWriting());
        float support = supportSet.get(response.getSupport());
        float maintenance = maintenanceSet.get(response.getMaintenance());
        float documentation = documentationSet.get(response.getDocumentation());
        float library = librarySet.get(response.getLibrary());

        float pertinence = calcPertinence(velocity, writing, support, maintenance, documentation, library);

        System.out.println("Log: " + pertinence);

        return langInfer(pertinence);
    }

    private static String langInfer(float pertinence) {

        if (pertinence <= 2.0F) {
            return "Linguagem C";
        } else if (pertinence <= 2.83F) {
            return "C++";
        } else if (pertinence <= 3.2F) {
            return "C#";
        } else if (pertinence <= 3.42F) {
            return "Rust";
        } else if (pertinence <= 3.57F) {
            return "Linguagem R";
        } else if (pertinence <= 4.0F) {
            return "Java";
        } else if (pertinence <= 4.16F) {
            return "Python";
        } else if (pertinence <= 4.28F) {
            return "Mojo";
        } else if (pertinence <= 4.42F) {
            return "GoLang";
        } else if (pertinence <= 5.0F) {
            return "JavaScript";
        } else if (pertinence >= 5.2F) {
            return "TypeScript";
        } else {
            return "PHP";
        }

    }

}
