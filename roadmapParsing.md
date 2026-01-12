# Checklist complète du parsing Cub3D (ordre logique)

## 📋 PHASE 1 : Validation initiale du fichier

*/- [ ] **1.1** Vérifier que le programme reçoit exactement 1 argument (le fichier .cub)/*
*/- [ ] **1.2** Vérifier que le fichier se termine par `.cub` (et uniquement `.cub`, pas `.cub.txt`)/*
*/- [ ] **1.3** Vérifier que le fichier existe/*
*/- [ ] **1.4** Vérifier que tu peux ouvrir le fichier (permissions de lecture)*/
*/- [ ] **1.5** Vérifier que le fichier n'est pas vide/*

## 📋 PHASE 2 : Lecture et stockage du fichier

*/- [ ] **2.1** Ouvrir le fichier/*
*/- [ ] **2.2** Lire le fichier ligne par ligne avec `get_next_line`/*
*/- [ ] **2.3** Stocker chaque ligne dans une liste chaînée ou un tableau dynamique/*
*/- [ ] **2.4** Compter le nombre total de lignes/*
*/- [ ] **2.5** Fermer le fichier/*
*/- [ ] **2.6** Vérifier qu'au moins une ligne a été lue/*

## 📋 PHASE 3 : Initialisation des structures

*/- [ ] **3.1** Créer ta structure principale (t_data ou équivalent)*/
*/- [ ] **3.2** Initialiser tous les pointeurs à NULL*/
*/- [ ] **3.3** Initialiser tous les compteurs à 0*/
*/- [ ] **3.4** Initialiser un compteur pour chaque élément (NO, SO, WE, EA, F, C)/*

## 📋 PHASE 4 : Parsing des éléments de configuration

### Pour chaque ligne (avant la map) :

- [ ] **4.1** Ignorer les lignes vides (seulement espaces/tabs/newline)
- [ ] **4.2** Trim les espaces en début de ligne
- [ ] **4.3** Identifier le type d'élément (NO, SO, WE, EA, F, C)

### Si c'est une TEXTURE (NO/SO/WE/EA) :

- [ ] **4.4** Vérifier que cet identifiant n'a pas déjà été parsé (pas de doublon)
- [ ] **4.5** Vérifier qu'il y a au moins un espace après l'identifiant
- [ ] **4.6** Skip les espaces/tabs entre l'identifiant et le chemin
- [ ] **4.7** Extraire le chemin du fichier texture
- [ ] **4.8** Vérifier qu'il n'y a pas de caractères après le chemin (sauf espaces/newline)
- [ ] **4.9** Vérifier que le chemin se termine par `.xpm`
- [ ] **4.10** Vérifier que le fichier .xpm existe
- [ ] **4.11** Vérifier que tu peux ouvrir le fichier .xpm
- [ ] **4.12** Stocker le chemin dans ta structure
- [ ] **4.13** Incrémenter le compteur pour cet élément

### Si c'est une COULEUR (F/C) :

- [ ] **4.14** Vérifier que cet identifiant n'a pas déjà été parsé (pas de doublon)
- [ ] **4.15** Vérifier qu'il y a au moins un espace après l'identifiant
- [ ] **4.16** Skip les espaces/tabs entre l'identifiant et les valeurs
- [ ] **4.17** Extraire les 3 valeurs RGB séparées par des virgules
- [ ] **4.18** Vérifier le format : `R,G,B` (avec possibilité d'espaces autour des virgules)
- [ ] **4.19** Vérifier qu'il y a exactement 3 nombres
- [ ] **4.20** Vérifier que chaque nombre est entre 0 et 255
- [ ] **4.21** Vérifier que ce sont bien des nombres (pas de lettres)
- [ ] **4.22** Vérifier qu'il n'y a pas de caractères après les valeurs RGB
- [ ] **4.23** Stocker les valeurs R, G, B dans ta structure
- [ ] **4.24** Incrémenter le compteur pour cet élément

### Vérification après parsing des éléments :

- [ ] **4.25** Vérifier que les 6 éléments ont été trouvés (NO, SO, WE, EA, F, C)
- [ ] **4.26** Vérifier qu'aucun élément n'apparaît plus d'une fois

## 📋 PHASE 5 : Identification du début de la map

- [ ] **5.1** Continuer à parcourir les lignes après les 6 éléments
- [ ] **5.2** Ignorer les lignes vides entre les éléments et la map
- [ ] **5.3** Identifier la première ligne contenant uniquement des caractères de map (0, 1, espace, N/S/E/W)
- [ ] **5.4** Vérifier qu'il reste au moins une ligne de map

## 📋 PHASE 6 : Parsing de la map

### Extraction de la map :

- [ ] **6.1** Stocker toutes les lignes de map dans un tableau 2D temporaire
- [ ] **6.2** Compter le nombre de lignes de la map
- [ ] **6.3** Trouver la ligne la plus longue (largeur max)
- [ ] **6.4** Vérifier que la map n'est pas vide

### Validation des caractères :

- [ ] **6.5** Parcourir chaque caractère de la map
- [ ] **6.6** Vérifier que chaque caractère est valide : '0', '1', ' ', 'N', 'S', 'E', ou 'W'
- [ ] **6.7** Compter le nombre de spawns (N/S/E/W) trouvés
- [ ] **6.8** Stocker la position du spawn (x, y)
- [ ] **6.9** Stocker la direction du spawn (N/S/E/W)

### Vérifications du spawn :

- [ ] **6.10** Vérifier qu'il y a exactement 1 spawn (ni 0, ni 2+)

## 📋 PHASE 7 : Normalisation de la map

- [ ] **7.1** Créer un tableau 2D avec une largeur uniforme (largeur max trouvée)
- [ ] **7.2** Pour chaque ligne trop courte, remplir la fin avec des espaces
- [ ] **7.3** Remplacer les tabs par des espaces (si nécessaire selon le sujet)
- [ ] **7.4** Stocker la map normalisée dans ta structure finale

## 📋 PHASE 8 : Validation de la fermeture de la map

### Vérification des bords :

- [ ] **8.1** Vérifier que la première ligne ne contient que des '1' et des espaces
- [ ] **8.2** Vérifier que la dernière ligne ne contient que des '1' et des espaces
- [ ] **8.3** Vérifier que la première colonne ne contient que des '1' et des espaces
- [ ] **8.4** Vérifier que la dernière colonne ne contient que des '1' et des espaces

### Vérification des espaces :

- [ ] **8.5** Pour chaque espace dans la map, vérifier les 4 cases adjacentes (haut, bas, gauche, droite)
- [ ] **8.6** Si un espace est adjacent à un '0' ou à un spawn → erreur (map ouverte)
- [ ] **8.7** Si un espace est adjacent à un bord de la map ET qu'il y a un '0' proche → erreur

### Alternative - Flood Fill :

- [ ] **8.8** OU utiliser un algorithme de flood fill depuis le spawn
- [ ] **8.9** Marquer toutes les cases accessibles ('0')
- [ ] **8.10** Vérifier qu'aucune case marquée ne touche un bord avec espace/vide

### Vérification finale :

- [ ] **8.11** Vérifier que le spawn n'est pas sur un bord non protégé
- [ ] **8.12** Vérifier qu'il existe au moins un chemin de '0' dans la map

## 📋 PHASE 9 : Gestion des erreurs

- [ ] **9.1** Si une erreur est détectée, afficher "Error\n" suivi d'un message explicite
- [ ] **9.2** Libérer TOUTE la mémoire allouée jusqu'à présent
- [ ] **9.3** Fermer tous les fichiers ouverts
- [ ] **9.4** Retourner une valeur d'erreur ou exit proprement

## 📋 PHASE 10 : Finalisation

- [ ] **10.1** Convertir les couleurs RGB en format hexadécimal si nécessaire pour la MLX
- [ ] **10.2** Calculer l'angle de départ du joueur selon sa direction (N=90°, S=270°, E=0°, W=180°)
- [ ] **10.3** Vérifier une dernière fois qu'aucun pointeur n'est NULL
- [ ] **10.4** S'assurer que toutes les données sont correctement stockées dans ta structure finale

## 📋 PHASE 11 : Tests et debug

- [ ] **11.1** Tester avec des maps valides simples
- [ ] **11.2** Tester avec des maps invalides (chaque type d'erreur)
- [ ] **11.3** Tester avec des espaces dans différentes configurations
- [ ] **11.4** Tester avec des lignes vides à différents endroits
- [ ] **11.5** Tester avec des chemins de textures invalides
- [ ] **11.6** Tester avec des valeurs RGB limites (0, 255, -1, 256)
- [ ] **11.7** Tester avec plusieurs spawns
- [ ] **11.8** Tester sans spawn
- [ ] **11.9** Tester avec des éléments manquants
- [ ] **11.10** Tester avec des doublons d'éléments
- [ ] **11.11** Vérifier avec Valgrind (0 leaks)
- [ ] **11.12** Vérifier avec la Norminette

---

## 🎯 Ordre de développement conseillé

1. Commence par les **phases 1-3** (validation fichier + structures)
2. Fais ensuite **phase 4** (parsing des textures et couleurs seulement)
3. Teste bien cette partie avant de continuer
4. Puis **phases 5-7** (extraction et normalisation de la map)
5. Ensuite **phase 8** (validation de la fermeture - la plus complexe)
6. Enfin **phases 9-11** (gestion d'erreurs et tests)

**Astuce :** Implémente une fonction d'affichage de ta structure après chaque phase pour vérifier que tout est bien parsé !

---

## 💡 Conseils supplémentaires

- Fais une fonction pour chaque vérification importante
- Écris des fonctions de debug pour afficher ta structure
- Teste chaque phase AVANT de passer à la suivante
- Utilise `valgrind --leak-check=full` régulièrement
- Crée tes propres fichiers .cub de test (valides ET invalides)
- Commente ton code au fur et à mesure
- N'hésite pas à refactoriser si ça devient trop complexe

Bon courage ! 🚀